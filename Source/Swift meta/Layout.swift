//
//  Layout.swift
//  Magicians iOS
//
//  Created by Alchemist on 2017/11/14.
//  Copyright © 2017年 alchemistxxd. All rights reserved.
//

import UIKit

class Layout: UICollectionViewFlowLayout {

    override func layoutAttributesForElements(in rect: CGRect) -> [UICollectionViewLayoutAttributes]? {
        var attrs = super.layoutAttributesForElements(in: rect) ?? []
        guard let cv = collectionView else {
            return nil
        }
        let contentOffset = cv.contentOffset
        
        var missingSections = IndexSet()
        
        for attr in attrs {
            if (attr.representedElementCategory == .cell) {
                missingSections.insert(attr.indexPath.section)
            }
        }
        for attr in attrs {
            if (attr.representedElementCategory == .supplementaryView) {
                missingSections.remove(attr.indexPath.section)
            }
        }
        for section in missingSections {
            let idxPath = IndexPath(item: 0, section: section)
            if let attr = self.layoutAttributesForSupplementaryView(ofKind: UICollectionElementKindSectionHeader, at: idxPath) {
                attrs.append(attr)
            }
        }
        
        for attr in attrs where attr.representedElementCategory == .supplementaryView {
            let section = attr.indexPath.section
            let numberOfItems = cv.numberOfItems(inSection: section)
            let firstObjectIndexPath = IndexPath(item: 0, section: section)
            let lastObjectIndexPath = IndexPath(item: max(0, numberOfItems - 1), section: section)
            
            var firstObjectAttrs: UICollectionViewLayoutAttributes?
            var lastObjectAttrs: UICollectionViewLayoutAttributes?
            
            if numberOfItems > 0 {
                firstObjectAttrs = self.layoutAttributesForItem(at: firstObjectIndexPath)
                lastObjectAttrs = self.layoutAttributesForItem(at: lastObjectIndexPath)
            } else {
                firstObjectAttrs = self.layoutAttributesForSupplementaryView(ofKind: UICollectionElementKindSectionHeader, at: firstObjectIndexPath)
                lastObjectAttrs = self.layoutAttributesForSupplementaryView(ofKind: UICollectionElementKindSectionFooter,
                                                                            at: lastObjectIndexPath)
            }
            
            let headerHeight = attr.frame.height
            var origin = attr.frame.origin
            origin.y = min(
                max(contentOffset.y + cv.contentInset.top, (firstObjectAttrs?.frame.minY ?? 0 - headerHeight)),
                lastObjectAttrs?.frame.maxY  ?? 0 - headerHeight
            )
            
            attr.zIndex = 1024
            attr.frame = CGRect(origin: origin, size: attr.frame.size)
        }
        return attrs
    }
}
